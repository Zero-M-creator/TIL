```C#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class Test : MonoBehaviour
{
    [SerializeField] private Text txt_name;
    [SerializeField] private Image img_name;

    private bool isCoolTime = false;

    private float currentTime = 5.0f;
    private float delayTime = 5.0f;

    void Update()
    {
        //img_name.sprite = //이미지 변경
        img_name.color = Color.red;
        if (isCoolTime)
        {
            currentTime -= Time.deltaTime;
            img_name.fillAmount = currentTime / delayTime;

            if(currentTime <= 0)
            {
                isCoolTime = false;
                currentTime = delayTime;
                img_name.fillAmount = currentTime;
            }
        }
    }
    public void Change()
    {
        txt_name.text = "변경됨";
        isCoolTime = true;
    }
}
```