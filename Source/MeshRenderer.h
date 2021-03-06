/**
	@brief rendering mesh to scene
	@author bodguy
	@date 17.07.17
	@todo 
	@bug 
*/

#ifndef MeshRenderer_h
#define MeshRenderer_h

#include "Renderer.h"

namespace Theodore {
	class Material; class Mesh; class Pipeline;
	class MeshRenderer : public Renderer {
	public:
		MeshRenderer();
		virtual ~MeshRenderer();

		void SetMaterial(Material* mat);
		void SetMesh(Mesh* mesh);
		Mesh* GetMesh() const;

	private:
		virtual void Update(float deltaTime) override;
		virtual void Render() override;
		virtual bool CompareEquality(const Object& rhs) const override;
		virtual bool Destroy() override;

		void InternalRender();

	protected:
		Material* mMaterial;
		Mesh* mMesh;
	};
}

#endif /* MeshRenderer_h */