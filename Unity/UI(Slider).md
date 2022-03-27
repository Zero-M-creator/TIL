```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class Test : MonoBehaviour
{
    //도트 데미지 구현
    [SerializeField] private Slider slider;
    private float dotTime = 1.0f;
    private float currentDotTime = 0.0f;

    private bool isClick;
    
    void Start()
    {
        currentDotTime = dotTime;
    }
    void Update()
    {
        if (isClick)
        {
            currentDotTime -= Time.deltaTime;
            if (currentDotTime <= 0)
            {
                slider.value -= Time.deltaTime;

                if(currentDotTime <= -1.0f)
                {
                    currentDotTime = dotTime;
                }
            }
        }
    }
    public void Button()
    {
        isClick = true;
    }
}
```