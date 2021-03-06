#include "Object.h"
#include "Vector3d.h"
#include "Quaternion.h"
#include "crc32.h"
#include "GameObject.h"
#include "Transform.h"

namespace Theodore {
	std::atomic<uint32_t> Unique_id::type_id;
	Object::Object(const std::string& name) :mName(name), mHashValue(CRC32_STR(name.c_str())) {

	}

	Object::Object(const Object& rhs) {
		// TODO
	}

	Object::~Object() {

	}

	bool Object::operator==(const Object& rhs) const {
		return mHashValue == rhs.mHashValue  && this->CompareEquality(rhs);
	}

	bool Object::operator!=(const Object& rhs) const {
		return !(*this == rhs && this->CompareEquality(rhs));
	}

	const std::string& Object::ToString() const {
		return mName;
	}

	const uint32_t Object::GetHashCode() const {
		return mHashValue;
	}

	uint32_t Object::GetInstanceID() const {
		return mInstanceId;
	}

	void Object::SetName(const std::string& name) {
		mName = name;
		mHashValue = CRC32_STR(name.c_str());
	}

	bool Object::Destroy(GameObject* obj) {
		if (!obj)
			return false;

		return obj->Destroy();
	}

	GameObject* Object::Instantiate(GameObject* original) {
		if(!original)
			return nullptr;
		
		return new GameObject(*original);
	}

	GameObject* Object::Instantiate(GameObject* original, const Vector3d& position) {
		if (!original)
			return nullptr;

		GameObject* clone = new GameObject(*original);
		clone->GetTransform()->SetPosition(position);

		return clone;
	}

	GameObject* Object::Instantiate(GameObject* original, const Vector3d& position, const Quaternion& rotation) {
		if (!original)
			return nullptr;

		GameObject* clone = new GameObject(*original);
		clone->GetTransform()->SetPosition(position);
		clone->GetTransform()->SetRotation(rotation);

		return clone;
	}
}