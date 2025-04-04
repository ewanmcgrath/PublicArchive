using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{

    public float moveSpeed; // Movement speed variable
    public float jumpForce; // Jump force variable

    public CharacterController controller; // Character controller declaration so you can use the players character controller 

    private Vector3 moveDirection; // Variable to store the players movement direction
    public float gravityScale; // Variable for gravity

    public Animator anim; // 

    // Moving the player with the camera
    public Transform pivot; // Pivot transform for use as means to move the player independent of the direction of the camera
    public float rotateSpeed; // Players rotation speed
    public GameObject playerModel; // Player

    public AudioSource jump; // Jump SFX

	// Use this for initialization
	void Start ()
    {
        controller = GetComponent<CharacterController>(); // Gets the player character controller
    }
	
	// Update is called once per frame
	void Update ()
    {
        float playersY = moveDirection.y; // Store the players y value 
        moveDirection = (transform.forward * Input.GetAxisRaw("Vertical")) + (transform.right *Input.GetAxisRaw("Horizontal")); // transform.forward gets the direction of the player based on input
        moveDirection = moveDirection.normalized * moveSpeed; // Normalize the players move direction so pressing multiple keys doesn't make you move faster
        moveDirection.y = playersY; // Resets the players y movement to mitigate normalization effects

        if (controller.isGrounded)
        {
            moveDirection.y = -3f;
            if (Input.GetButtonDown("Jump"))
            {
                moveDirection.y = jumpForce;
                jump.Play(); // Play the jump SFX
            }
        }

        if (!controller.isGrounded)
        {
            moveDirection.y = moveDirection.y + (Physics.gravity.y * gravityScale * Time.deltaTime);
        }

        moveDirection.y = moveDirection.y + (Physics.gravity.y * gravityScale * Time.deltaTime);
        controller.Move(moveDirection * Time.deltaTime);

        // Move the player based on camera direction
        if(Input.GetAxisRaw("Horizontal") != 0 || Input.GetAxisRaw("Vertical") != 0)
        {
            transform.rotation = Quaternion.Euler(0f, pivot.rotation.eulerAngles.y, 0f);
            Quaternion newRotation = Quaternion.LookRotation(new Vector3(moveDirection.x, 0f, moveDirection.z));
            playerModel.transform.rotation = Quaternion.Slerp(playerModel.transform.rotation, newRotation, rotateSpeed * Time.deltaTime);
        }

        anim.SetBool("isGrounded", controller.isGrounded); // Set the players animator boolean to be true - I.e. the player is not in the air
        anim.SetFloat("Speed", (Mathf.Abs(Input.GetAxisRaw("Vertical")) + Mathf.Abs(Input.GetAxisRaw("Horizontal")))); // Set the speed variable of the animator so the players run animation happens
    }
}
