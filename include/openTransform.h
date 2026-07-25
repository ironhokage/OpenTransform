#pragma once

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace open3D {
    class Transform {
    public:

        enum SpaceType {
            WorldSpace,
            LocalSpace
        };

        inline void SetParent();
        void GetParent() const; // to add [[nodiscard]]

        // Set World Coordinates(Position, Rotation & Scale)
        inline void SetWorldPosition(const glm::vec3& position);
        inline void SetWorldRotation(const glm::quat& rotation);
        inline void SetWorldScale(const glm::vec3& scale);

        // Set Local Coordinates(Position, Rotation & Scale)
        inline void SetLocalPosition(const glm::vec3& position);
        inline void SetLocalRotation(const glm::quat& rotation);
        inline void SetLocalScale(const glm::vec3& scale);

        // Get Local Coordinates(Position, Rotation, Scale & Euler Angles)
        [[nodiscard]] inline glm::vec3 GetLocalPosition() const;
        [[nodiscard]] inline glm::quat GetLocalRotation() const;
        [[nodiscard]] inline glm::vec3 GetLocalScale() const;
        [[nodiscard]] inline glm::vec3 GetLocalEulerAngles() const;

        // Get World Coordinates(Position, Rotation, Scale & Euler Angles)
        inline glm::vec3 GetWorldPosition();
        inline glm::quat GetWorldRotation();
        inline glm::vec3 GetWorldScale();
        inline glm::vec3 GetWorldEulerAngles();

        // Methods to obtain the Forward, Right & Up world axes
        [[nodiscard]] inline glm::vec3 Forward();
        [[nodiscard]] inline glm::vec3 Right();
        [[nodiscard]] inline glm::vec3 Up();

        inline void SetWorldPositionAndRotation(glm::vec3& position, glm::quat& rotation);
        inline void SetLocalPositionAndRotation(const glm::vec3& localPosition, const glm::quat& localRotation);

        inline void RotateQuaternion(const glm::quat& angle);
        inline void RotateEuler(const glm::vec3 &axis, float angle);
        inline void Translate(const glm::vec3& translation);
        inline void LookAt(const glm::vec3& position,  const glm::vec3& axis);

        inline int GetTransformSiblingIndex();

        inline static void Destroy();

    private:
        glm::vec3 localPosition;
        glm::quat localRotation;
        glm::vec3 localScale;

        // Used in the getter functions when decomposing the global matrix
        glm::vec3 position;
        glm::quat rotation;
        glm::vec3 scale;
        glm::vec3 skew;
        glm::vec4 perspective;

        bool localMatrixDirty = true;
        bool globalMatrixDirty = true;
    };


    // Implementation of the functions

    inline void Transform::SetParent() {
    }

    inline void Transform::SetWorldPosition(const glm::vec3 &position) {
    }

    inline void Transform::SetWorldRotation(const glm::quat &rotation) {
    }

    inline void Transform::SetWorldScale(const glm::vec3 &scale) {
    }

    inline void Transform::SetLocalPosition(const glm::vec3 &position) {
    }

    inline void Transform::SetLocalRotation(const glm::quat &rotation) {
    }

    inline void Transform::SetLocalScale(const glm::vec3 &scale) {
    }

    inline glm::vec3 Transform::GetLocalPosition() const {
    }

    inline glm::quat Transform::GetLocalRotation() const {
    }

    inline glm::vec3 Transform::GetLocalScale() const {
    }

    inline glm::vec3 Transform::GetLocalEulerAngles() const {
    }

    inline glm::vec3 Transform::GetWorldPosition() {
    }

    inline glm::quat Transform::GetWorldRotation() {
    }

    inline glm::vec3 Transform::GetWorldScale() {
    }

    inline glm::vec3 Transform::GetWorldEulerAngles() {
    }

    inline glm::vec3 Transform::Forward() {
    }

    inline glm::vec3 Transform::Right() {
    }

    inline glm::vec3 Transform::Up() {
    }

    inline void Transform::SetWorldPositionAndRotation(glm::vec3 &position, glm::quat &rotation) {
    }

    inline void Transform::SetLocalPositionAndRotation(const glm::vec3 &localPosition, const glm::quat &localRotation) {
    }

    inline void Transform::RotateQuaternion(const glm::quat &angle) {
    }

    inline void Transform::RotateEuler(const glm::vec3 &axis, float angle) {
    }

    inline void Transform::Translate(const glm::vec3 &translation) {
    }

    inline void Transform::LookAt(const glm::vec3 &position, const glm::vec3 &axis) {
    }

    inline int Transform::GetTransformSiblingIndex() {
    }

    inline void Transform::Destroy() {
    }
}