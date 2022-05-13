/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param a ListNode类vector 指向这些数链的开头
     * @return ListNode类
     */
    ListNode* solve(vector<ListNode*>& a) {
        // write code here
        ListNode* head=new ListNode(-1);
        ListNode* pre=head;
        ListNode* nums[a.size()];
        for(int ii=0;ii<a.size();ii++){
            nums[ii]=a[ii];
        }
        int count=0;
        while(1){
            for(int ii=0;ii<a.size();ii++){
                if(nums[ii]){
                    pre->next=new ListNode(nums[ii]->val);
                    pre=pre->next;
                    nums[ii]=nums[ii]->next;
                    count=0;
                }else{
                    count++;
                }
                if(count==a.size()) break;
            }
            if(count==a.size()) break;
        }
        return head->next;
    }
};