```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Test : MonoBehaviour
{
    [SerializeField] private LayerMask layerMask; //특정마스크만 레이저를 맞게함
    [SerializeField] private GameObject go_BulletPrefab; //Prefab 스크립트넣고..등등 여러설정한 객체를 하드에 저장한형태

    private float createTime = 1.0f;
    private float currentCreateTime = 0.0f;
    void Update()
    {
        currentCreateTime += Time.deltaTime;
        if(currentCreateTime >= createTime)
        {
            RaycastHit hitInfo;
            //(자신의 위치에서, 앞으로, 맞는 객체 저장, 10거리, 특정 layerMask만 충돌)
            if (Physics.Raycast(this.transform.position, this.transform.forward, out hitInfo, 10.0f, layerMask))
            {
                if (hitInfo.transform.tag == "Player")
                {
                    //(생성 prefab, 생성 위치, 방향)
                    Instantiate(go_BulletPrefab, transform.position, Quaternion.LookRotation(hitInfo.transform.position - transform.position)); //prefab 생성 메서드
                }
                Debug.Log(hitInfo.transform.name);

                currentCreateTime = 0.0f;
            }
        }
      
    }
}
```

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Test : MonoBehaviour
{
    private float createTime = 1.0f;
    private float currentCreateTime = 0.0f;
    [SerializeField] private GameObject go_BulletPrefab;

    void Update()
    {
        Collider[] col = Physics.OverlapSphere(transform.position, 5.0f); //구 안에 모든 콜라이더를 담음

        if(col.Length > 0)
        {
            for(int i = 0; i < col.Length; i++)
            {
                Transform tf_Target = col[i].transform;

                if(tf_Target.tag == "Player")
                {
                    transform.rotation = Quaternion.LookRotation(tf_Target.position - this.transform.position);

                    currentCreateTime += Time.deltaTime;
                    if (currentCreateTime >= createTime)
                    {
                        Instantiate(go_BulletPrefab, transform.position, Quaternion.LookRotation(tf_Target.position - this.transform.position));
                        currentCreateTime = 0.0f;

                        /* ex) 투명상태 물리피해 x
                        GameObject temp = Instantiate(go_BulletPrefab, transform.position, Quaternion.LookRotation(tf_Target.position - this.transform.position));
                        // 2개의 콜라이더간 충돌 무시
                        Physics.IgnoreCollision(temp.GetComponent<Collider>(), tf_Target.GetComponent<Collider>());
                        */
                    }
                }
            } 
        }
    }
}
```

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    [SerializeField] private float speed;
    [SerializeField] private float damage;

    void Update()
    {
        transform.position += transform.forward * speed * Time.deltaTime;
    }
    private void OnTriggerEnter(Collider other) //트리거가 콜라이더에 들어갔을때
    {
        Debug.Log(other.transform.name + "에게 데미지" + damage + "을 입혔습니다.");
        Destroy(this.gameObject);
    }
}
```