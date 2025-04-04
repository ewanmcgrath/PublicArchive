using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Spin : MonoBehaviour
{
    public float rotateSpeed;

    private void Update()
    {
        Rotate();
    }

    public void Rotate()
    {
        transform.Rotate(0, 0, 50 * rotateSpeed * Time.deltaTime);
    }
}
