#include "Building/IronMine.hpp"
#include "Resource/ResourceBall.hpp"
#include "Resource/ResourceBalls.hpp"
#include "ValuesAndTypes.hpp"

IronMine::IronMine(Field &field, const FieldCoord &fieldCoord, ResourceBalls &resourceBalls_, Road &road): Mine{field, fieldCoord, 1, resourceBalls_, road} {
    text.setString("IM");
    renderTexture.draw(text);
}

void IronMine::mine(){
	Mine::mine();
	resourceBalls.append(new ResourceBall{field, road, getCoord(), ResourceType::iron});
}
