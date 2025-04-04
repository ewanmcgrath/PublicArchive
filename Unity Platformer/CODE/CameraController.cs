using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraController : MonoBehaviour
{
    public Transform target; // Variable to hold the players transform

    public Vector3 offset; // Vector3 to hold the offset values for the camera - How far it is from the players transform

    public bool useOffsetValues; // Boolean to set whether the camera is a fixed offset that you determine or a 'dynamic' one

    public float rotateSpeed = 5.0f; // Value to set speed of the camera
    //public float smoothSpeed = 0.125f;

    public Transform pivot; // Variable to hold the pivot game object

    public float maxViewAngle; // The max view angle of the camera
    public float minViewAngle; // The min view angle of the camera

    public bool invertY; // Boolean to set in inspector - Will change if the camera is inverted on the Y axis

    // Use this for initialization
    void Start ()
    {
        if (!useOffsetValues) // Dyanmic offset
        {
            offset = target.position - transform.position;
        }

        pivot.transform.position = target.transform.position;
        //pivot.transform.parent = target.transform;

        pivot.transform.parent = null;

        Cursor.lockState = CursorLockMode.Locked; // Lock the cursor the the center of the screen - Hides it in Unity engine
	}
	
	void LateUpdate ()
    {
        // Move the pivot point based on the players transform
        pivot.transform.position = target.transform.position;

        // Get the X axis input and rotate the pivot
        float horizontal = Input.GetAxis("Mouse X") * rotateSpeed;
        pivot.Rotate(0, horizontal, 0);

        // Get the Y axis input and rotate the pivot
        float vertical = Input.GetAxis("Mouse Y") * rotateSpeed;

        if(invertY)
        {
            pivot.Rotate(vertical, 0, 0);
        }
        else
        {
            pivot.Rotate(-vertical, 0, 0);
        }

        // Limit the up/down camera rotation
        if(pivot.rotation.eulerAngles.x > maxViewAngle && pivot.rotation.eulerAngles.x < 180)
        {
            pivot.rotation = Quaternion.Euler(maxViewAngle, 0, 0);
        }

        if(pivot.rotation.eulerAngles.x > 180 && pivot.rotation.eulerAngles.x < 360f + minViewAngle)
        {
            pivot.rotation = Quaternion.Euler(360f + minViewAngle, 0, 0);
        }

        // Transform the camera based on the current player transform and the offset
        float desiredYAngle = pivot.eulerAngles.y; // Using euler angles object to set the desired angle to be the pivots y value
        float desiredXAngle = pivot.eulerAngles.x;

        Quaternion rotation = Quaternion.Euler(desiredXAngle, desiredYAngle,0); // Create a quaternion variable and set it's value to be a euler 3 axis variable
        transform.position = target.position - (rotation * offset); // Transform the cameras position based on the players position minus the rotation and offset

        // Realign the camera - Stop it from going down too much
        if (transform.position.y < target.position.y)
        {
            transform.position = new Vector3(transform.position.x, target.position.y, transform.position.z);
        }
        transform.LookAt(target); // LookAt function to make the camera transform point towards the player
	}
}
