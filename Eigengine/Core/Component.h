#pragma once

namespace EigenCore
{
	class GameObject;

	class Component
	{
	public:
		// Dependency injection, note that each Component MUST have an owner
		explicit Component(GameObject* const parent, const size_t updatePriority = 0) 
			: m_parent(parent), m_updatePriority(updatePriority) {}
		virtual ~Component() {}
		virtual void update(float dt) = 0;
		inline size_t getPriority() const { return m_updatePriority; }

	private:
		GameObject* const m_parent;
		int m_updatePriority;
	};
};