class SegmentTree{
    vector<int>tree;
    public:
    vector<int>nodes;
    SegmentTree(vector<int>v){
        int n = v.size();
        nodes = v;
        tree.resize(4*n);
        build(1,0,n-1);
    }
    int build(int node,int l,int r){
        if(l==r){
            tree[node] = l;
            return l;
        }
        int mid = l+(r-l)/2;
        int left = build(2*node,l,mid);
        int right = build(2*node+1,mid+1,r);
        return tree[node] = nodes[left]>nodes[right]?left:right;
    }
    int query(int node,int l,int r,int ql,int qr){
        if(ql==l&&qr==r){
            return tree[node];
        }
        if(ql>r||qr<l){
            return -1;
        }
        int mid = l+(r-l)/2;
        int left = query(2*node,l,mid,ql,min(mid,qr));
        int right = query(2*node+1,mid+1,r,max(ql,mid+1),qr);
        if(left==-1)return right;
        if(right==-1)return left;
        return nodes[left]>nodes[right]?left:right;
    }
    int update(int node,int l,int r,int tr){  
        if(l==tr&&r==tr){
            nodes[tr] = -1;
            return l;
        }
        if(tr>r||tr<l)return tree[node];
        int mid  = l+(r-l)/2;
        int left = update(2*node,l,mid,tr);
        int right = update(2*node+1,mid+1,r,tr); 
        if(left==-1)tree[node] = right;
        if(right==-1)tree[node] = left;
        return tree[node] = nodes[left]>nodes[right]?left:right;
    }
};
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>vp;
        int n = profits.size();
        for(int i=0;i<n;i++){
            vp.push_back({capital[i],profits[i]});
        }
        sort(vp.begin(),vp.end());
        for(int i=0;i<n;i++){
            profits[i] = vp[i].second;
            capital[i] = vp[i].first;
        }
        SegmentTree* sg = new SegmentTree(profits);
        if(k>n)k = n;
        while(k){
            auto it= upper_bound(capital.begin(),capital.end(),w);
            if(it==capital.begin())return w;
            it--;
            int ind = it-capital.begin();
            int pro = sg->query(1,0,n-1,0,ind);
            if(sg->nodes[pro]==-1)return w;
            w+=profits[pro];
            sg->update(1,0,n-1,pro);
            k--;
        }
        return w;
    }
};