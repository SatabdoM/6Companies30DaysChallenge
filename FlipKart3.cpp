class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) 
    {
        int fl=0;
        while(fl==0)
        {
            unordered_map<int,ListNode*>map;
            ListNode* tail=head;
            int prefix_sum=0;
            while(tail!=NULL)
            {
                prefix_sum+=tail->val;
                if(prefix_sum==0)
                {
                    head=tail->next;
                    break;
                }
                else if(map.find(prefix_sum)!=map.end())//there exists same prefix sum in the map
                {
                    ListNode* start=map[prefix_sum];
                    start->next=tail->next;
                    break;
                }
                else
                {
                    map[prefix_sum]=tail;
                    tail=tail->next;
                }
            }
            if(tail==NULL)
                return head;
        }
        return head;        
    }
};
