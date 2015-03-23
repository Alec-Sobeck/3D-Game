#ifndef ENGINE_ENEMY_H
#define ENGINE_ENEMY_H

#include <memory>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include "physics/aabb.h"
#include "physics/aabs.h"
#include "graphics/camera.h"
#include "graphics/model.h"
#include "entity.h"

/**
* Entity is the base class for all things that exist in the world with some sort of model, and position.
* @author Alec Sobeck
* @author Matthew Robertson
*/
class Enemy
{
public:
	AABB boundingBox;
	/** An integer which uniquely identifies this entity in the world. Generated by {@link #getNextEntityID} */
	const int entityID;
	float health;
	float maxHealth;
	bool wasChasing = false;
	/**
	 * Constructs a new Entity, assigning it the next valid entityID available and a camera with position
	 * and rotation of 0.
	 */
	Enemy();
	/**
	* Creates a new Entity and assigns it the provided entityID, model, and camera.
	* @param entityID an int which must uniquely identify this Entity. It is suggested that this
	* be a value generated from {@link #getNextEntityID()}
	* @param model a Model that will be used for this entity
	* @param camera a Camera that will be used for this entity
	*/
	Enemy(std::shared_ptr<Model> model, Camera camera);
	~Enemy();
	float getX();
	float getY();
	float getZ();
	bool affectedByGravity();
	void setAffectedByGravity(bool isAffectedByGravity);
	std::shared_ptr<Model> getModel();
	AABB getAABB();
	void setModel(std::shared_ptr<Model> newModel);
	Camera *getCamera();
	void setCamera(Camera camera);
	/**
	* Moves the Camera the specified amount.
	* @param movement a glm::vec3 that describes the movement of the Camera
	*/
	void move();
	void accel(glm::vec3 movement);
	void rotate(glm::vec3 rotation);
	glm::vec3 getRotation();
	glm::vec3 getPosition();
	void onGameTick(Entity &player, float deltaTime);
	float getHealthPercent();

protected:
	/** A model somehow associated to this entity. */
	std::shared_ptr<Model> model;
	/** A camera which controls the movement of this entity. */
	Camera camera;
	glm::vec3 velocity;
	glm::vec3 acceleration;
	double maxMoveSpeed;
private:
	/** True if the entity should follow the laws of gravity, or false if gravity ignores them. */
	bool isAffectedByGravity;
};
#endif
