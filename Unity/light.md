```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Test : MonoBehaviour
{
    //라이트 컴포넌트 조절
    private Light theLight;

    private float targetIntensity; //목표 세기
    private float currentIntensity;//현재 세기
    private void Start()
    {
        theLight = GetComponent<Light>();
        currentIntensity = theLight.intensity;
        targetIntensity = Random.Range(0.4f, 1.0f);
    }
    void Update()
    {
        if(Mathf.Abs(targetIntensity - currentIntensity) >= 0.01)
        {
            if((targetIntensity - currentIntensity) >= 0)
            {
                currentIntensity += Time.deltaTime * 3.0f;
            }
            else
            {
                currentIntensity -= Time.deltaTime * 3.0f;
            }
            theLight.intensity = currentIntensity;
            theLight.range = currentIntensity + 10;
        }
        else
        {
            targetIntensity = Random.Range(0.4f, 1.0f);
        }
    }
}
```