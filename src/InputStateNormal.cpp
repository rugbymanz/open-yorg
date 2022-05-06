#include <SFML/Window/Event.hpp>

#include "Building/CrystalMine.hpp"
#include "InputStateFutureRoad.hpp"
#include "InputStateNormal.hpp"
#include "Building/Transporter.hpp"
#include "Field/FieldCell.hpp"
#include "Input.hpp"
#include "Game.hpp"
#include "Algorithms.hpp"
#include "Building/Base.hpp"
#include "Resource/Crystal.hpp"
#include "Enemy/CasualEnemy.hpp"
#include "Building/Mine.hpp"
#include "Building/Cannon.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "Resource/Iron.hpp"
#include "Building/IronMine.hpp"
#include "Building/Wall.hpp"

InputStateNormal::InputStateNormal(Field &field, Interface &interface, PathSearchField &pathSearchField, Enemies &enemies, Bullets &bullets, DamageCircles &damageCircles_, ResourceBalls &resourceBalls_, Road &road_, Input &input): InputState{field, interface, pathSearchField, enemies, bullets, damageCircles_, resourceBalls_, road_, input}{};

void InputStateNormal::process(const sf::Event &event){
    if (event.type == sf::Event::EventType::MouseWheelScrolled)
        processMouseWheelScroll(event.mouseWheelScroll);

    if (event.type == sf::Event::EventType::KeyPressed)
        processKeys(event.key);

    if (event.type == sf::Event::EventType::MouseButtonReleased)
        processMouseClick(event.mouseButton);
}

bool InputStateNormal::isValidBuildingPosition(const FieldCoord &position){
    return field.get(position).fieldCellType == FieldCell::FieldCellType::empty;
}

void InputStateNormal::processMouseClick(const sf::Event::MouseButtonEvent  &mouseButton){
    if (mouseButton.button == sf::Mouse::Button::Left)
        processMouseLeftClick({mouseButton.x, mouseButton.y});
}

void InputStateNormal::processMouseWheelScroll(const sf::Event::MouseWheelScrollEvent &mouseWheelScroll){
    double zoom = - mouseWheelScroll.delta * ZOOM_SPEED;
    sf::View view = Game::window->getView();
    view.zoom(1 + zoom);
    Game::window->setView(view);
}

void InputStateNormal::build(const sf::Keyboard::Key &key){
    const FieldCoord &position = interface.selectedCell;

    if (!isValidBuildingPosition(position)){
        std::cout << "Invalid building postion" << std::endl;
        return;
    }
    if (interface.selectedCell != NONE_FIELD_CELL){
		FieldCell *fieldCell = nullptr;
        switch (key) {
        case sf::Keyboard::B:
            fieldCell = field.set(new Base{ field, interface.selectedCell });
            break;
        case sf::Keyboard::R:
            fieldCell = field.set(new Crystal{ interface.selectedCell });
            break;
        case sf::Keyboard::E:
            new CasualEnemy{ interface.selectedCell, enemies, pathSearchField, bullets, field, damageCircles};
            break;
        case sf::Keyboard::M:
            fieldCell = field.set(new CrystalMine{ field, interface.selectedCell, resourceBalls, road });
            break;
        case sf::Keyboard::C:
            fieldCell = field.set(new Cannon{ interface.selectedCell, enemies, bullets, damageCircles });
            break;
        case sf::Keyboard::T:
            fieldCell = field.set(new Transporter{ interface.selectedCell });
            break;
        case sf::Keyboard::I:
            fieldCell = field.set(new Iron{interface.selectedCell});
            break;
        case sf::Keyboard::O:
            fieldCell = field.set(new IronMine{ field, interface.selectedCell, resourceBalls, road });
            break;
        case sf::Keyboard::W:
            fieldCell = field.set(new Wall{ interface.selectedCell });
            break;
        }
		road.showFutureRoad(fieldCell);
		if(fieldCell)
			input.state = new InputStateFutureRoad{field, interface, pathSearchField, enemies, bullets, damageCircles, resourceBalls, road, input};
	}
}

void InputStateNormal::upgrade(Building &building){
    building.upgrade();
}


void InputStateNormal::processKeys(const sf::Event::KeyEvent &key){
    sf::View view = Game::window->getView();

    switch(key.code){
    case sf::Keyboard::Key::Left:
        view.move(-VIEW_MOVE_SPEED, 0);
        break;
    case sf::Keyboard::Key::Right:
        view.move(VIEW_MOVE_SPEED, 0);
        break;
    case sf::Keyboard::Key::Down:
        view.move(0, VIEW_MOVE_SPEED);
        break;
    case sf::Keyboard::Key::Up:
        view.move(0, -VIEW_MOVE_SPEED);
        break;
    case sf::Keyboard::Key::F1:
        if(FieldCell &fieldCell {field.get( interface.selectedCell)}; fieldCell.fieldCellType == FieldCell::FieldCellType::building)
            upgrade(static_cast<Building&>(fieldCell));
        else
            std::cerr << "Cannot be upgraded" << std::endl;
    case sf::Keyboard::Key::B:
    //fall-through
    case sf::Keyboard::Key::R:
    case sf::Keyboard::Key::E:
    case sf::Keyboard::Key::M:
    case sf::Keyboard::Key::C:
    case sf::Keyboard::Key::T:
    case sf::Keyboard::I:
    case sf::Keyboard::O:
    case sf::Keyboard::W:
        build(key.code);
        break;
    default:
        std::cerr << std::endl << "detected unrecognized Key event" << std::endl;
    }

    Game::window->setView(view);
}

void InputStateNormal::processMouseLeftClick(const sf::Vector2i &clickPosition){
    sf::Vector2f floatCoord = Game::window->mapPixelToCoords(clickPosition);
    FieldCoord fieldCell = Algorithms::vector2fToFieldCoord(floatCoord);
    std::cerr << std::endl << fieldCell.x << ' ' << fieldCell.y << ' ';

    if( (fieldCell.x < FIELD_LENGTH && floatCoord.x >= 0) && (fieldCell.y < FIELD_WIDTH && floatCoord.y >= 0) )
        interface.selectCell(fieldCell); 
    else
        std::cerr << "out of field bounds" << std::endl;
}