/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int,Node*>mp;

    void tra(Node* org,Node* cln){
        
        vector<Node*>tmp;

        for(auto i:org->neighbors){
            // Node* n=new Node(i->val);
            if(mp.find(i->val)==mp.end()){
                Node* n=new Node(i->val);
                // vis.insert(i->val);
                mp[i->val]=n;
                tmp.push_back(n);
                tra(i,n);
            }else{
                Node* n=mp[i->val];
                tmp.push_back(n);
            }
        }
        cln->neighbors=tmp;
    }
    
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)      return NULL;
        if(node->val==0){
            return new Node();
        }


        Node* ans=new Node(node->val);
        // vis.insert(node->val);
        mp[node->val]=ans;
        tra(node,ans);
        return ans;

        
    }
};
