#pragma once
#include"Vector3.h"
#include"Novice.h"
#include"Matrix4x4.h"

struct Line {
	Vector3 origin;	//!< �n�_
	Vector3 diff; //!< �I�_�ւ̍����x�N�g��
};

struct  Ray {
	Vector3 origin; //!< �n�_
	Vector3 diff; //!< �I�_�ւ̍����x�N�g��
};

struct  Segment {
	Vector3 origin; //!< �n�_
	Vector3 diff; //!< �I�_�ւ̍����x�N�g��
};

struct Sphere {
	Vector3 center;
	float radius;
};
