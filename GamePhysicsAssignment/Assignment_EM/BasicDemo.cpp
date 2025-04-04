#include "BasicDemo.h"

BasicDemo::BasicDemo()
:
BulletOpenGLApplication(),
m_bApplyForce(false),
m_pExplosion(0),
m_bCanExplode(true) {

}

void BasicDemo::InitializePhysics() {
	// create the collision configuration
	m_pCollisionConfiguration = new btDefaultCollisionConfiguration();
	// create the dispatcher
	m_pDispatcher = new btCollisionDispatcher(m_pCollisionConfiguration);
	// create the broadphase
	m_pBroadphase = new btDbvtBroadphase();
	// create the constraint solver
	m_pSolver = new btSequentialImpulseConstraintSolver();
	// create the world
	m_pWorld = new btDiscreteDynamicsWorld(m_pDispatcher, m_pBroadphase, m_pSolver, m_pCollisionConfiguration);

	// create our scene's physics objects
	CreateObjects();
}

void BasicDemo::ShutdownPhysics() {
	delete m_pWorld;
	delete m_pSolver;
	delete m_pBroadphase;
	delete m_pDispatcher;
	delete m_pCollisionConfiguration;
}

void BasicDemo::CreateObjects() 
{
	////////// create a ground plane
	CreateGameObject(new btBoxShape(btVector3(1,50,30)), 0, btVector3(0.3f, 0.2f, 0.9f), btVector3(0.0f, 0.0f, 20.0f));

	/////////// create a wall at the back
	CreateGameObject(new btBoxShape(btVector3(50, 50,1)), 0, btVector3(0.6f, 0.6f, 0.2f), btVector3(0.0f, 50.0f, 50.0f));
	// Side walls
	CreateGameObject(new btBoxShape(btVector3(30, 1, 30)), 0, btVector3(0.6f, 0.6f, 0.2f), btVector3(50.0f, 30.0f, 20.0f));
	CreateGameObject(new btBoxShape(btVector3(30, 1, 30)), 0, btVector3(0.6f, 0.6f, 0.2f), btVector3(-50.0f, 30.0f, 20.0f));

	// Dividers
	CreateGameObject(new btBoxShape(btVector3(5, 1, 30)), 0, btVector3(0.6f, 0.6f, 0.2f), btVector3(30.0f, 0.0f, 20.0f));
	CreateGameObject(new btBoxShape(btVector3(5, 1, 30)), 0, btVector3(0.6f, 0.6f, 0.2f), btVector3(-30.0f, 0.0f, 20.0f));
	CreateGameObject(new btBoxShape(btVector3(5, 1, 30)), 0, btVector3(0.6f, 0.6f, 0.2f), btVector3(0.0f, 0.0f, 20.0f));

	// Front wall
	CreateGameObject(new btBoxShape(btVector3(5, 50, 1)), 0, btVector3(0.6f, 0.6f, 0.2f), btVector3(0.0f, 0.0f, -10.0f));
	
	////////// create a lot of rectangles for the pachinko
	CreateGameObject(new btBoxShape(btVector3(0.5, 0.5, 15)), 0, btVector3(1.0f, 1.0f, 1.0f), btVector3(0.0f, 80.0f, 40.0f));
	CreateGameObject(new btBoxShape(btVector3(0.5, 0.5, 15)), 0, btVector3(1.0f, 1.0f, 1.0f), btVector3(4.0f, 82.0f, 40.0f));
	CreateGameObject(new btBoxShape(btVector3(0.5, 0.5, 15)), 0, btVector3(1.0f, 1.0f, 1.0f), btVector3(8.0f, 84.0f, 40.0f));
	CreateGameObject(new btBoxShape(btVector3(0.5, 0.5, 15)), 0, btVector3(1.0f, 1.0f, 1.0f), btVector3(12.0f, 86.0f, 40.0f));
	CreateGameObject(new btBoxShape(btVector3(0.5, 0.5, 15)), 0, btVector3(1.0f, 1.0f, 1.0f), btVector3(16.0f, 88.0f, 40.0f));

	CreateGameObject(new btBoxShape(btVector3(0.5, 0.5, 15)), 0, btVector3(1.0f, 1.0f, 1.0f), btVector3(-4.0f, 82.0f, 40.0f));
	CreateGameObject(new btBoxShape(btVector3(0.5, 0.5, 15)), 0, btVector3(1.0f, 1.0f, 1.0f), btVector3(-8.0f, 84.0f, 40.0f));
	CreateGameObject(new btBoxShape(btVector3(0.5, 0.5, 15)), 0, btVector3(1.0f, 1.0f, 1.0f), btVector3(-12.0f, 86.0f, 40.0f));
	CreateGameObject(new btBoxShape(btVector3(0.5, 0.5, 15)), 0, btVector3(1.0f, 1.0f, 1.0f), btVector3(-16.0f, 88.0f, 40.0f));

	// Lower prongs
	CreateGameObject(new btBoxShape(btVector3(0.5, 0.5, 15)), 0, btVector3(1.0f, 1.0f, 1.0f), btVector3(0.0f, 60.0f, 40.0f));
	CreateGameObject(new btBoxShape(btVector3(0.5, 0.5, 15)), 0, btVector3(1.0f, 1.0f, 1.0f), btVector3(4.0f, 58.0f, 40.0f));
	CreateGameObject(new btBoxShape(btVector3(0.5, 0.5, 15)), 0, btVector3(1.0f, 1.0f, 1.0f), btVector3(8.0f, 56.0f, 40.0f));
	CreateGameObject(new btBoxShape(btVector3(0.5, 0.5, 15)), 0, btVector3(1.0f, 1.0f, 1.0f), btVector3(12.0f, 54.0f, 40.0f));
	CreateGameObject(new btBoxShape(btVector3(0.5, 0.5, 15)), 0, btVector3(1.0f, 1.0f, 1.0f), btVector3(16.0f, 52.0f, 40.0f));

	CreateGameObject(new btBoxShape(btVector3(0.5, 0.5, 15)), 0, btVector3(1.0f, 1.0f, 1.0f), btVector3(-4.0f, 58.0f, 40.0f));
	CreateGameObject(new btBoxShape(btVector3(0.5, 0.5, 15)), 0, btVector3(1.0f, 1.0f, 1.0f), btVector3(-8.0f, 56.0f, 40.0f));
	CreateGameObject(new btBoxShape(btVector3(0.5, 0.5, 15)), 0, btVector3(1.0f, 1.0f, 1.0f), btVector3(-12.0f, 54.0f, 40.0f));
	CreateGameObject(new btBoxShape(btVector3(0.5, 0.5, 15)), 0, btVector3(1.0f, 1.0f, 1.0f), btVector3(-16.0f, 52.0f, 40.0f));

	// randomized prongs
	srand(static_cast <unsigned> (time(0)));

	float low1 = 40.0f;
	float high1 = -40.0f;
	float low2 = 10.0f;
	float high2 = 90.0f;

	int loop = 0;
	while (loop < 200)
	{
		float value1 = low1 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (high1 - low1)));
		float value2 = low2 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (high2 - low2)));
		CreateGameObject(new btBoxShape(btVector3(0.5, 0.5, 15)), 0, btVector3(0.0f, 0.0f, 0.0f), btVector3(value1, value2, 40.0f));
		loop++;
	}

	///////// create an invisible wall
	//CreateGameObject(new btBoxShape(btVector3(50, 50, 1)), 0, btVector3(100.0f, 100.0f, 100.0f), btVector3(0.0f, 50.0f, 30.0f));

	// create our red box, but store the pointer for future usage
	m_pBox = CreateGameObject(new btBoxShape(btVector3(1,1,1)), 1.0, btVector3(1.0f, 0.2f, 0.2f), btVector3(0.0f, 10.0f, 100000000.0f));

	// create a second box
	CreateGameObject(new btBoxShape(btVector3(1,1,1)), 1.0, btVector3(0.0f, 0.2f, 0.8f), btVector3(1.25f, 20.0f, 10000000000.0f));

	// create a trigger volume
	m_pTrigger = new btCollisionObject();
	// create a box for the trigger's shape
	m_pTrigger->setCollisionShape(new btBoxShape(btVector3(1,0.25,1)));
	// set the trigger's position
	btTransform triggerTrans;
	triggerTrans.setIdentity();
	triggerTrans.setOrigin(btVector3(0,1.5,0));
	m_pTrigger->setWorldTransform(triggerTrans);
	// flag the trigger to ignore contact responses
	m_pTrigger->setCollisionFlags(btCollisionObject::CF_NO_CONTACT_RESPONSE);
	// add the trigger to our world
	m_pWorld->addCollisionObject(m_pTrigger);

	// create a yellow sphere
	CreateGameObject(new btSphereShape(1.0f), 1.0, btVector3(0.7f, 0.7f, 0.0f), btVector3(-5.0, 10.0f, 100000000000.0f));

	// create a green cylinder
	CreateGameObject(new btCylinderShape(btVector3(1,1,1)), 1.0, btVector3(0.0f, 0.7f, 0.0f), btVector3(-2, 10.0f, 100000000000000.0f));

	// create a vertex cloud defining a square-based pyramid
	btVector3 points[5] = {btVector3(-0.5,1,1),
		btVector3(-0.5,1,-1),
		btVector3(-0.5,-1,1),
		btVector3(-0.5,-1,-1),
		btVector3(1,0,0)};
	// create our convex hull
	btConvexHullShape* pShape = new btConvexHullShape(&points[0].getX(),5);
	// initialize the object as a polyhedron
	pShape->initializePolyhedralFeatures();
	// create the game object using our convex hull shape
	CreateGameObject(pShape, 1.0, btVector3(1,1,1), btVector3(5, 15, 0));

/*ADD*/		// create two shapes for the rod and the load
/*ADD*/		btCollisionShape* pRod = new btBoxShape(btVector3(1.5f, 0.2f, 0.2f));
/*ADD*/		btCollisionShape* pLoad = new btSphereShape(0.5f);
/*ADD*/		// create a transform we'll use to set each object's position
/*ADD*/		btTransform trans;
/*ADD*/		trans.setIdentity();
/*ADD*/		// create our compound shape
/*ADD*/		btCompoundShape* pCompound = new btCompoundShape();
/*ADD*/		// add the rod
/*ADD*/		pCompound->addChildShape(trans, pRod);
/*ADD*/		trans.setOrigin(btVector3(-1.75f, 0.0f, 10000000000.0f));
/*ADD*/		// add the top load
/*ADD*/		pCompound->addChildShape(trans, pLoad);
/*ADD*/		trans.setIdentity();
/*ADD*/		// add the bottom load
/*ADD*/		trans.setOrigin(btVector3(1.75f, 0.0f, 100000000000000.0f));
/*ADD*/		pCompound->addChildShape(trans, pLoad);
/*ADD*/		// create a game object using the compound shape
/*ADD*/		CreateGameObject(pCompound, 2.0f, btVector3(0.8,0.4,0.1), btVector3(-4, 10.0f, 100000000000.0f));

}

void BasicDemo::CollisionEvent(btRigidBody* pBody0, btRigidBody* pBody1) {
	// did the box collide with the trigger?
	if (pBody0 == m_pBox->GetRigidBody() && pBody1 == m_pTrigger ||
		pBody1 == m_pBox->GetRigidBody() && pBody0 == m_pTrigger) {
			// if yes, create a big green box nearby
			CreateGameObject(new btBoxShape(btVector3(2,2,2)), 2.0, btVector3(0.3, 0.7, 0.3), btVector3(5, 10, 0));
	}

	// Impulse testing
	if (pBody0 == m_pExplosion || pBody1 == m_pExplosion) {
		// get the pointer of the other object
		btRigidBody* pOther;
		pBody0 == m_pExplosion ? pOther = (btRigidBody*)pBody1 : pOther = (btRigidBody*)pBody0;
		// wake the object up
		pOther->setActivationState(ACTIVE_TAG);
		// calculate the vector between the object and
		// the center of the explosion
		btVector3 dir = pOther->getWorldTransform().getOrigin() - m_pExplosion->getWorldTransform().getOrigin();
		// get the distance
		float dist = dir.length();
		// calculate the impulse strength
		float strength = EXPLOSION_STRENGTH;
		// follow an inverse-distance rule
		if (dist != 0.0) strength /= dist;
		// normalize the direction vector
		dir.normalize();
		// apply the impulse
		pOther->applyCentralImpulse(dir * strength);
	}
}

void BasicDemo::Keyboard(unsigned char key, int x, int y) {
	// call the base implementation first
	BulletOpenGLApplication::Keyboard(key, x, y);
	switch(key) {
	// Force testing
	case 'g': 
		{
			// if 'g' is held down, apply a force
			m_bApplyForce = true; 
			// prevent the box from deactivating
			m_pBox->GetRigidBody()->setActivationState(DISABLE_DEACTIVATION);
			break;
		}
	// Impulse testing
	case 'e':
		{
			// don't create a new explosion if one already exists
			// or we haven't released the key, yet
			if (m_pExplosion || !m_bCanExplode) break;
			// don't let us create another explosion until the key is released
			m_bCanExplode = false;
			// create a collision object for our explosion
			m_pExplosion = new btCollisionObject();
			m_pExplosion->setCollisionShape(new btSphereShape(3.0f));
			// get the position that we clicked
			RayResult result;
			Raycast(m_cameraPosition, GetPickingRay(x, y), result, true);
			// create a transform from the hit point
			btTransform explodeTrans;
			explodeTrans.setIdentity();
			explodeTrans.setOrigin(result.hitPoint);
			m_pExplosion->setWorldTransform(explodeTrans);
			// set the collision flag
			m_pExplosion->setCollisionFlags(btCollisionObject::CF_NO_CONTACT_RESPONSE);
			// add the explosion trigger to our world
			m_pWorld->addCollisionObject(m_pExplosion);
			break;
		}
	}
}

void BasicDemo::KeyboardUp(unsigned char key, int x, int y) {
	// call the base implementation first
	BulletOpenGLApplication::KeyboardUp(key, x, y);
	switch(key) {
	// Force testing
	case 'g': 
		{
			// if 'g' is let go, stop applying the force
			m_bApplyForce = false; 
			// allow the object to deactivate again
			m_pBox->GetRigidBody()->forceActivationState(ACTIVE_TAG); 
			break;
		}
	// Impulse testing
	case 'e': m_bCanExplode = true; break;
	}
}

void BasicDemo::UpdateScene(float dt) {
	// call the base implementation first
	BulletOpenGLApplication::UpdateScene(dt);

	// Force testing
	if (m_bApplyForce) {
		if (!m_pBox) return;
		// apply a central upwards force that exceeds gravity
		m_pBox->GetRigidBody()->applyCentralForce(btVector3(0, 20, 0));
	}

	// Impulse testing
	if (m_pExplosion) {
		// destroy the explosion object after one iteration
		m_pWorld->removeCollisionObject(m_pExplosion);
		delete m_pExplosion;
		m_pExplosion = 0;
	}
}