#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

class baseTransform
{
    struct TransformData {

        glm::vec3 localPosition;
        glm::quat localRotation;
        glm::vec3 localScale;

        bool isStatic;
        int parentIndex = -1;

        glm::mat4 localMatrix;
        glm::mat4 worldMatrix;

        bool localMatrixDirty = true;
        bool globalMatrixDirty = true;

    };

public:
    explicit baseTransform(const TransformData &m_tdata)
        : m_Tdata(m_tdata) {
    }

private:
    inline void ComputeWorldMatrix();
    inline void ComputeLocalMatrix();

protected:
    TransformData m_Tdata;
};

inline void baseTransform::ComputeWorldMatrix() {
}

inline void baseTransform::ComputeLocalMatrix() {
}

