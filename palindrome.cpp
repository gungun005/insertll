while(head!=NULL)
    {
        ans.push_back(head->val);
        head=head->next;
    }
    int start=0;
    int end=ans.size()-1;
    while(start<=end)
    {
        if(ans[start]!=ans[end])
        return false;
        start++;
        end--;
    }
    return true;
    }
