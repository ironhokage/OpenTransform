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

        enum SpaceType {
            WorldSpace,
            LocalSpace
        };

    public:

        inline void SetParent();
        void GetParent() const; // to add [[nodiscard]]

        // Set Coordinates(Position, Rotation & Scale)
        inline void SetPosition(const glm::vec3& position, SpaceType space);
        inline void SetRotation(const glm::quat& rotation, SpaceType space);
        inline void SetScale(const glm::vec3& scale, SpaceType space);

        // Get Coordinates(Position, Rotation, Scale & Euler Angles)
        [[nodiscard]] inline glm::vec3 GetPosition(SpaceType space) const;
        [[nodiscard]] inline glm::quat GetRotation(SpaceType space) const;
        [[nodiscard]] inline glm::vec3 GetScale(SpaceType space) const;
        [[nodiscard]] inline glm::vec3 GetEulerAngles(SpaceType space) const;

        // In here you add the values you want to change to position and rotation
        inline void UpdatePositionAndRotation(glm::vec3& currentPosition, glm::quat& currentRotation, SpaceType space);

        // Methods to obtain the Forward, Right & Up world axes
        [[nodiscard]] static inline glm::vec3 Forward(SpaceType space);
        [[nodiscard]] inline glm::vec3 Right(SpaceType space);
        [[nodiscard]] inline glm::vec3 Up(SpaceType space);

        inline void SetPositionAndRotation(glm::vec3& position, glm::quat& rotation, SpaceType space);

        inline void RotateQuaternion(const glm::quat& angle);
        inline void RotateEuler(const glm::vec3 &axis, float angle);
        inline void Translate(const glm::vec3& translation, SpaceType space);
        inline void LookAt(const glm::vec3& position,  const glm::vec3& axis);

        inline int GetTransformSiblingIndex();

        inline static void Destroy();
        inline static void CreateNewTransform();

    private:

        struct TransformData {

            glm::vec3 localPosition;
            glm::quat localRotation;
            glm::vec3 localScale;

            bool isStatic;
            int parentIndex = -1;

            glm::mat3x4 localMatrix;
            glm::mat3x4 worldMatrix;

            bool localMatrixDirty = true;
            bool globalMatrixDirty = true;

        };

        std::vector<TransformData> transform_data;

        glm::vec3 position;
        glm::quat rotation;
        glm::vec3 scale;
        glm::vec3 skew;
        glm::vec4 perspective;

    };

    inline void Transform::SetParent() {
    }

    inline void Transform::SetPosition(const glm::vec3 &position, SpaceType space) {

    }

    inline void Transform::SetRotation(const glm::quat &rotation, SpaceType space) {
    }

    inline void Transform::SetScale(const glm::vec3 &scale, SpaceType space) {
    }

    inline glm::vec3 Transform::GetPosition(SpaceType space) const {
        switch (space) {
            case WorldSpace:
                break;
            case LocalSpace:
                break;
            default: ;
        }
    }

    inline glm::quat Transform::GetRotation(SpaceType space) const {
        switch (space) {
            case WorldSpace:
                break;
            case LocalSpace:
                break;
            default: ;
        }
    }

    inline glm::vec3 Transform::GetScale(SpaceType space) const {
        switch (space) {
            case WorldSpace:
                break;
            case LocalSpace:
                break;
            default: ;
        }
    }

    inline glm::vec3 Transform::GetEulerAngles(SpaceType space) const {
        switch (space) {
            case WorldSpace:
                break;
            case LocalSpace:
                break;
            default: ;
        }
    }

    inline void Transform::UpdatePositionAndRotation(glm::vec3 &currentPosition, glm::quat &currentRotation,
        SpaceType space) {
    }

    inline glm::vec3 Transform::Forward(SpaceType space) {
        switch (space) {
            case WorldSpace:
                break;
            case LocalSpace:
                break;
            default: ;
        }
    }

    inline glm::vec3 Transform::Right(SpaceType space) {
        switch (space) {
            case WorldSpace:
                break;
            case LocalSpace:
                break;
            default: ;
        }
    }

    inline glm::vec3 Transform::Up(SpaceType space) {
        switch (space) {
            case WorldSpace:
                break;
            case LocalSpace:
                break;
            default: ;
        }
    }

    inline void Transform::SetPositionAndRotation(glm::vec3 &position, glm::quat &rotation, SpaceType space) {
    }

    inline void Transform::RotateQuaternion(const glm::quat &angle) {
    }

    inline void Transform::RotateEuler(const glm::vec3 &axis, float angle) {
    }

    inline void Transform::Translate(const glm::vec3 &translation, SpaceType space) {
    }

    inline void Transform::LookAt(const glm::vec3 &position, const glm::vec3 &axis) {
    }

    inline int Transform::GetTransformSiblingIndex() {
    }

    inline void Transform::Destroy() {
    }

    inline void Transform::CreateNewTransform() {
    }
}
