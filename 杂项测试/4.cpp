//计算该函数的时间复杂度？O(logn)吗????

LinkNode* GetNode(Linklist head,int ii){
    int jj;
    ListNode* p;
    p=head,jj=0;

    while(p->next && jj< ii){
        p=p->next;
        jj++;
    }

    if(ii==jj){
        return (p);
    }
    else{
        return (NULL);
    }
}