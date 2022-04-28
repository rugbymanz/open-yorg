#include "Building/CrystalMine.hpp"
#include "Resource/ResourceBall.hpp"
#include "Resource/ResourceBalls.hpp"
#include "ValuesAndTypes.hpp"

CrystalMine::CrystalMine(Field &field, const FieldCoord &fieldCoord, ResourceBalls &resourceBalls_, Road &road): Mine{field, fieldCoord, 1, resourceBalls_, road} {
    text.setString("CM");
    renderTexture.draw(text);
}

void CrystalMine::mine(){
	Mine::mine();
	resourceBalls.append(new ResourceBall{field, road, getCoord(), ResourceType::crystal});
}
