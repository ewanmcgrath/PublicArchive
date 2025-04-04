using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Respawn : MonoBehaviour
{
    [SerializeField] private Transform Player;
    [SerializeField] private Transform RespawnPoint;
    //[SerializeField] private AudioSource Death;

    private void OnTriggerEnter(Collider other)
    {
        Player.transform.position = RespawnPoint.transform.position;
        //StartCoroutine("RespawnPlayer", 2f);
        //Death.Play();
    }

    //IEnumerator RespawnPlayer(float spawnDelay)
    //{
    //    yield return new WaitForSeconds(spawnDelay);
    //    Player.transform.position = RespawnPoint.transform.position;
    //}
}
