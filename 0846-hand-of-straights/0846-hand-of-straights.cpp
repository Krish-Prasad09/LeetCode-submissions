class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        map<int, int> mp;
        if (n % groupSize != 0) return false;
        for (auto it : hand) mp[it]++;
        
        // YOUR EXACT STRUCTURE INTACT
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            
            // If we've already used up all copies of this card in previous groups, skip it
            if (it->second == 0) continue;
            
            int key = it->first;
            int freq = it->second; // This tells us exactly how many groups MUST start with this card
            
            // Instead of tracking 'cnt' across multiple outer loops, we verify the whole group right here
            for (int i = 0; i < groupSize; i++) {
                
                // If we don't have enough of the consecutive cards to finish the group, it's impossible
                if (mp[key + i] < freq) {
                    return false;
                }
                
                // Deduct the cards we just used so they aren't double-counted
                mp[key + i] -= freq;
            }
        }
        
        // If we make it through the whole map without returning false, the hand is perfect
        return true; 
    }
};