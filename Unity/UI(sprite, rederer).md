```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

[System.Serializable]
public class Dialogue
{
    [TextArea]
    public string dialogue;
    public Sprite cg;
}
public class Test : MonoBehaviour
{
    [SerializeField] private SpriteRenderer sprite_StandingCG;
    [SerializeField] private SpriteRenderer sprite_DialoueBox;
    [SerializeField] private Text txt_Dialogue;

    private bool isDialogue = false;
    private int count;
    [SerializeField] private Dialogue[] dialogue;

    private void OnOff(bool flag)
    {
        sprite_StandingCG.gameObject.SetActive(flag);
        sprite_DialoueBox.gameObject.SetActive(flag);
        txt_Dialogue.gameObject.SetActive(flag);

    }
    public void showDialogue()
    {
        OnOff(true);
        count = 0;
        isDialogue = true;
        nextDialogue();
    }

    private void nextDialogue()
    {
        txt_Dialogue.text = dialogue[count].dialogue;
        sprite_StandingCG.sprite = dialogue[count].cg;
        count++;
    }

    void Update()
    {
        if (isDialogue)
        {
            if (Input.GetKeyDown(KeyCode.E))
            {
                if (count < dialogue.Length)
                    nextDialogue();
                else
                    OnOff(false);
            }
        }
    }
}
```