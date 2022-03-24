```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Test : MonoBehaviour
{
    //콜라이더 : 충돌 관련..
    private BoxCollider col;
    void Start()
    {
        col = GetComponent<BoxCollider>();
    }
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.W)) //한번만 발동
        {
            //속성
            Debug.Log("col.bounds" + col.bounds); //collider 중심 값 + 객체 포지션 값
            Debug.Log("col.bounds.extents" + col.bounds.extents); //객체 길이 반, 수정 불가
            Debug.Log("col.bounds.extents.x" + col.bounds.extents.x); // 수정 불가
            Debug.Log("col.size" + col.size);
            Debug.Log("col.center" + col.center);

            col.size = new Vector3(3, 3, 3);
          
        //collider 메소드
        if (Input.GetMouseButtonDown(0)) {
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            RaycastHit hitInfo;
            //raycast(레이저 좌표, 맞은 곳 좌표, 사정거리)
            if(col.Raycast(ray, out hitInfo, 1000))
            {
                this.transform.position = hitInfo.point; //마우스 클릭한 좌표로 이동
            }

        }
    }
    //is trigger 충돌을 체크만하고 물리적 충돌을 하지 않음, 영역에 닿으면 적 출현 이벤트 같은 곳
    //is trigger가 작동된 상태에서 콜라이더 영역 안으로 다른 콜라이더가 들어오면 발동
    private void OnTriggerEnter(Collider other)
    {

    }
    private void OnTriggerExit(Collider other) //나가면 발동
    {

    }
    private void OnTriggerStay(Collider other) // 머물고 있으면 발동 ex)힐
    {
        other.transform.position += new Vector3(0, 0, 0.01f);
    }
    //물리적 충돌이 일어났을 때, is trigger = false;
    private void OnCollsiionEnter(Collision collision) //충돌 시 
    {

    }
    private void OnCollisionExit(Collision collision) //충돌이 끝나면
    {

    }
    private void OnCollisionStay(Collision collision)
    {

    }
}
```