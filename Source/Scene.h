#ifndef Scene_h
#define Scene_h

#include <memory>
#include <vector>
#include "Object.h"

namespace Quark {
	class Scene : public Object {
		friend class SceneManager;
		friend class GameObject;
	public:
		explicit Scene(const std::string& name);
		virtual ~Scene();

		bool IsActive() const;
		void SetActive(bool value);
		void Attach(GameObject* object);
		GameObject* Find(const std::string& name) const;
		GameObject* FindWithTag(const std::string& tag) const;
		std::shared_ptr<std::vector<GameObject*> > FindGameObjectsWithTag(const std::string& tag) const;
		void print(const char* format, ...);

		// Only at once being called when scene object is created
		virtual void OnAwake() {}
		// being called whenever scene is activated
		virtual void OnStart() {}
		// every frame
		virtual void OnUpdate() {}
		// every frame like OnUpdate function for rendering purpose
		virtual void OnRender() {}
		// before being called SetActive function (false -> true)
		virtual void OnEnable() {}
		// before being called SetActive function (true -> false)
		virtual void OnDisable() {}
		// when scene object is destroyed
		virtual void OnDestroy() {}

	private:
		virtual void Update(double deltaTime) final;
		virtual void Render() final;
		virtual bool CompareEquality(const Object& rhs) const final;
		virtual bool Destroy() final;
		bool Remove(GameObject* object);

	protected:
		std::vector<GameObject*> mGameObjects;
		int32_t mBuildIndex;
		SceneManager* mManager;
		bool mActive;
	};
}

#endif /* Scene_h */