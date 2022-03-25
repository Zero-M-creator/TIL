애니메이션 컴포넌트

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Test : MonoBehaviour
{
    private Animation anim;
    private void Start()
    {
        anim = GetComponent<Animation>();
    }
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.W))
        {
            anim.Play("Cube_Animation");
            anim.PlayQueued("Cube_Animation"); //끝나면 재생
            anim.Blend("Cube_Animation"); //동시에 섞어서 재생
            anim.CrossFade("Cube_Animation"); //실행 되던 거 자연스럽게 사라지고 대체
            if (!anim.IsPlaying("Cube_Animation"))
                anim.Play("Cube_Animation");
            anim.Stop(); //정지
            anim.wrapMode = WrapMode.Loop; //랩 모드 변경
        }
    }
}
```