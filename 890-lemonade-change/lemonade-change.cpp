class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> note(3,0);
       
        int n = bills.size();
        int total = 0;

        int five = 0;
        int ten = 0;

        for(int i = 0; i < n; i++){
            
            if(bills[i] == 5){
                five++;
            }

            else if(bills[i] == 10){

                if(five < 1){
                    return false;
                }
                else{
                    five -= 1;
                    ten += 1;
                }

            }

            else{

                if(ten >= 1 && five >= 1 ){
                    five -= 1;
                    ten -= 1;
                }

                else if(five >= 3){
                    five -= 3;
                }

                else{
                    return false;
                }
            }

        }

        return true;
    }
};