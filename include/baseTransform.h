#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <utility>

class baseTransform
{
    struct TransformData {

        glm::vec3 localPosition;
        glm::quat localRotation;
        glm::vec3 localScale;

        bool isStatic;
        int parentIndex = -1;
        std::vector<int> children;

        glm::mat4 worldMatrix;

        bool isDirty = true;
    };

public:
    explicit baseTransform(TransformData transform_data)
        : transform_data(std::move(transform_data)) {
    }

private:
    inline glm::mat4 ComputeLocalToWorldMatrix();
    inline void ComputeWorldMatrix();

protected:
    TransformData transform_data;
};

inline glm::mat4 baseTransform::ComputeLocalToWorldMatrix()
{
    const glm::mat4 localPositionMatrix = glm::translate(glm::mat4(1.0f), transform_data.localPosition);
    const glm::mat4 localScaleMatrix = glm::scale(glm::mat4(1.0f), transform_data.localScale);
    const glm::mat4 localRotationMatrix = glm::mat4_cast(transform_data.localRotation);

    return localPositionMatrix * localRotationMatrix * localScaleMatrix;
}

inline void baseTransform::ComputeWorldMatrix() {
}



