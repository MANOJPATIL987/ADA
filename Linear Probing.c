
typedef struct
{
    int hash[15000];
} MyHashSet;

MyHashSet myHashSetCreate()
{
    MyHashSet *obj = (MyHashSet *)malloc(sizeof(MyHashSet));
    memset(obj, 0, sizeof(MyHashSet));
    return obj;
}

void myHashSetAdd(MyHashSet *obj, int key)
{
    int tmp = ((5381 + key) * 33) % 15000;
    while (obj->hash[tmp])
    {
        if (obj->hash[tmp] != key)
            tmp = (tmp + 1) % 15000;
        else
            return;
    }
    obj->hash[tmp] = key == 0 ? -1 : key;
}

void myHashSetRemove(MyHashSet *obj, int key)
{
    int tmp = ((5381 + key) * 33) % 15000;
    key = key == 0 ? -1 : key;
    while (obj->hash[tmp])
    {
        if (obj->hash[tmp] != key)
            tmp = (tmp + 1) % 15000;
        else
        {
            obj->hash[tmp] = 2000000;
            return;
        }
    }
}

bool myHashSetContains(MyHashSet obj, int key)
{
    int tmp = ((5381 + key) * 33) % 15000;
    key = key == 0 ? -1 : key;
    while (obj->hash[tmp])
    {
        if (obj->hash[tmp] == key)
            return true;
        tmp = (tmp + 1) % 15000;
    }
    return false;
}

void myHashSetFree(MyHashSet *obj)
{
    free(obj);
    obj = NULL;
}