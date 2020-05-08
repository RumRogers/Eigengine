#pragma once

#include <vector>
#include <queue>
#include "Component.h"
#include "../Math/Transform2D.h"

namespace EigenCore
{
	class Scene;
	
	// Functor for the priority queue ordering
	struct CompareComponents
	{
		bool operator()(const Component& lhs, const Component& rhs) const
		{
			return lhs.getPriority() > rhs.getPriority();
		}
	};

	class GameObject
	{
	public:
		// Dependency injection ftw here
		explicit GameObject(Scene* const owner) : m_owner(owner) {}
		EigenMath::Transform2D transform;

	private:
		Scene* m_owner;
		std::priority_queue<Component, std::vector<Component>, CompareComponents> m_components;
	};
}