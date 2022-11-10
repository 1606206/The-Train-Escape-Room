#include "Camera.h"
#include "../physics/BulletWorld.h"
#include <bullet/btBulletDynamicsCommon.h>

Camera Camera::MAIN_CAMERA;
Camera Camera::SAVE_CAMERA;

void Camera::setupColliders()
{
	//btCollisionShape* groundShape = new btBoxShape(btVector3(btScalar(.4), btScalar(.5), btScalar(.35)));
	btCollisionShape* groundShape = new btCylinderShape(btVector3(btScalar(.05), btScalar(.05), btScalar(2)));

	btTransform groundTransform;
	groundTransform.setIdentity();
	groundTransform.setOrigin(btVector3(position.x, position.y, position.z));

	btScalar mass(0.);

	//rigidbody is dynamic if and only if mass is non zero, otherwise static
	bool isDynamic = (mass != 0.f);

	btVector3 localInertia(0, 0, 0);
	if (isDynamic)
		groundShape->calculateLocalInertia(mass, localInertia);

	//using motionstate is optional, it provides interpolation capabilities, and only synchronizes 'active' objects
	btDefaultMotionState* myMotionState = new btDefaultMotionState(groundTransform);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, groundShape, localInertia);
	btRigidBody* body = new btRigidBody(rbInfo);

	body->setUserPointer(this);
	my_rigid_body = body;

	BulletWorld::WORLD->my_collision_shapes.push_back(groundShape);
	BulletWorld::WORLD->my_dynamics_world->addRigidBody(body);
}

void Camera::syncColliders()
{
	btTransform groundTransform;
	groundTransform.setIdentity();
	groundTransform.setOrigin(btVector3(position.x, position.y, position.z));

	my_rigid_body->setWorldTransform(groundTransform);
	my_rigid_body->getMotionState()->setWorldTransform(groundTransform);
}
void Camera::sitDown(const Seient* seient)
{
	SAVE_CAMERA = MAIN_CAMERA;
	MAIN_CAMERA.sit = true;
	MAIN_CAMERA.position.x = seient->my_transform.position().x;
	MAIN_CAMERA.position.y = seient->my_transform.position().y;
	MAIN_CAMERA.position.z = 1.25;
	//TODO angle things
}

void Camera::standUp()
{
	SAVE_CAMERA.horizontal_angle = MAIN_CAMERA.horizontal_angle;
	SAVE_CAMERA.vertical_angle = MAIN_CAMERA.vertical_angle;
	MAIN_CAMERA = SAVE_CAMERA;
	
}

/*
void show_cam_vectors()
{
	glm::vec3 direction(
		cos(vertical_angle) * cos(horizontal_angle),
		sin(horizontal_angle),
		sin(vertical_angle)
	);

	glm::vec3 left = glm::vec3(
		cos(horizontal_angle + PI / 2),
		sin(horizontal_angle + PI / 2),
		0
	);

	glm::vec3 up = glm::cross(direction, left);

	cout << "DIRECTION:" << std::endl;
	cout << "x " << direction[0] << ", y " << direction[1] << ", z " << direction[2] << endl;
	cout << "RIGHT:" << std::endl;
	cout << "x " << left[0] << ", y " << left[1] << ", z " << left[2] << endl;
	cout << "UP:" << std::endl;
	cout << "x " << up[0] << ", y " << up[1] << ", z " << up[2] << endl;
}
*/