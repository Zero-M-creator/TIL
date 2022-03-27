```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class Test : MonoBehaviour
{
    //InputField 입출금
    [SerializeField] private Text txt_Money;
    [SerializeField] private InputField inputTxt_Money;

    private int currentMoney;
    
    public void Input()
    {
        currentMoney += int.Parse(inputTxt_Money.text);
        txt_Money.text = currentMoney.ToString();
    }
    public void Output()
    {
        currentMoney -= int.Parse(inputTxt_Money.text);
        txt_Money.text = currentMoney.ToString();
    }
}
```