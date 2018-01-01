#include "../Include/Systems/RenderSystem.h"
#include "../Include/Components/RenderComponent.h"

using namespace BulletDream;

Export void RenderSystem::update(Engine* engine) {
	auto* window = engine->getMainWindow();

	if (window == nullptr) {
		return;
	}
	window->clear(sf::Color::Blue);

	auto entities = engine->getEntities();
	int entityCount = entities.size();
	for (int e = 0; e < entityCount; e++) {
		GameObject* entity = entities[e];
		if (entity != nullptr) {
			for (auto comp : entity->components) {
				RenderComponent* renderComp = dynamic_cast<RenderComponent*>(comp.second);

				if (renderComp) {
					renderComp->render(*window);
				}
			}
		}
	}

	window->display();
}