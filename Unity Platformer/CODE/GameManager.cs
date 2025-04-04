using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro; // Allows for use of Text Mesh Pro
using UnityEngine.SceneManagement; // Enable scene management

public class GameManager : MonoBehaviour
{
    public int currentDiamonds; // Variable to hold the amount of diamonds the player has
    public TMP_Text diamondCount; // Text mesh pro variable to hold the text
    public AudioSource collectSound; // SFX for when the player collects a diamond
    public AudioSource youWin; // SFX for when the player finishes the game on the 3rd level
    private bool lastLevel; // Boolean to check against to see if it's the last level 

    public void Start()
    {
        // Hide the cursor at the start of the level
        Cursor.visible = false;

        // Create a temporary reference to the current scene
        Scene currentScene = SceneManager.GetActiveScene(); // Create a variable of type scene which is equal to the current scene

        // Check if the current scene is level3/the last level
        if (currentScene.name == "Level3")
        {
            lastLevel = true; // Set boolean to true
        }

    }

    public void AddDiamond(int addDiamond)
    {
        currentDiamonds += addDiamond; // Add to the diamond count
        diamondCount.text = "Diamonds " + currentDiamonds + "/5"; // Display the diamond count in the TMP text
        if(currentDiamonds == 1 || currentDiamonds > 1) // If the player collides with a diamond play the SFX
        {
            collectSound.Play();
        }
        if(currentDiamonds == 5)
        {
            SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1); // Loads the next scene
            if (lastLevel == true) // Check the lastLevel boolean, if it's true play the win SFX and change the text
            {
                youWin.Play();
                diamondCount.text = "You've Won! Alt+F4 to exit";
                //if (Input.GetKey(KeyCode.Escape))
                //{
                //    Application.Quit();
                //}
            }
        }
    }
}
