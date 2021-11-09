using System;
using UnityEngine.UI;
using UnityEngine;

public class Main : MonoBehaviour
{
    public Text textAnciennePositionX;
    public Text textAnciennePositionY;
    public Text textNouvellePositionX;
    public Text textNouvellePoistionY;
    public Text textDistanceParcourue;

    public InputField inputX;
    public InputField inputY;

    private float currentX;
    private float currentY;
    private float lastX;
    private float lastY;

    private float distanceParcourue;

    public GameObject myGameObject;

    // Start is called before the first frame update
    void Start()
    {
        myGameObject = this.gameObject;

        lastX = myGameObject.transform.position.x;
        currentX = myGameObject.transform.position.x;

        lastY = myGameObject.transform.position.y;
        currentY = myGameObject.transform.position.y;

        distanceParcourue = calculateDistance(lastX, lastY, currentX, currentY);

        textAnciennePositionX.text = "Ancienne position en X : " + lastX.ToString();
        textAnciennePositionY.text = "Ancienne position en Y : " + lastY.ToString();
        textNouvellePositionX.text = "Position en X : " + currentX.ToString();
        textNouvellePoistionY.text = "Position en Y : " + currentY.ToString();
        textDistanceParcourue.text = "Distance Parcourue : " + distanceParcourue.ToString() + " m.";
    }

    float calculateDistance(float ancienX, float ancienY, float newX, float newY)
    {
        return Mathf.Sqrt(Mathf.Pow((newX - ancienX),2) + Mathf.Pow((newY - ancienY), 2));
    }

    void changeCoordinate(float xCoordinate, float yCoordiante)
    {
        myGameObject.transform.position = new Vector3(xCoordinate, 0, yCoordiante);
    }

    public void changeData()
    {
        lastX = currentX;
        currentX = Convert.ToInt32(inputX.text);

        Debug.Log("Position X : " + currentX.ToString());
        Debug.Log("Ancienne Position X : " + lastX.ToString());
        Debug.Log("InputField X : " + inputX.text);

        lastY = currentY;
        currentY = Convert.ToInt32(inputY.text);

        Debug.Log("Position Y : " + currentY.ToString());
        Debug.Log("Ancienne Position Y : " + lastY.ToString());
        Debug.Log("InputField Y : " + inputY.text);

        distanceParcourue = calculateDistance(lastX, lastY, currentX, currentY);

        Debug.Log("Distance Parcourue : " + distanceParcourue.ToString());

        textAnciennePositionX.text = "Ancienne position en X : " + lastX.ToString();
        textAnciennePositionY.text = "Ancienne position en Y : " + lastY.ToString();
        textNouvellePositionX.text = "Position en X : " + currentX.ToString();
        textNouvellePoistionY.text = "Position en Y : " + currentY.ToString();
        textDistanceParcourue.text = "Distance Parcourue : " + distanceParcourue.ToString() + " m.";

        changeCoordinate(currentX, currentY);
    }
}
