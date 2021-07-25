int romanToDecimal(string &str) {
    // code here
    int num=0;
    
    
    while(str.length()){
        
        if(str.length()>=2 and (str.substr(0,2))=="IV"){
            num = num + 4;
            str=str.substr(1+1);
        }
        else if(str.length()>=2 and (str.substr(0,2))=="IX"){
            num  = num + 9;
            str=str.substr(1+1);
        }
        else if(str.length()>=2 and (str.substr(0,2))=="XL"){
            num  =num +  40;
            str=str.substr(1+1);
        }
       else if(str.length()>=2 and (str.substr(0,2))=="XC"){
            num  =num +  90;
            str=str.substr(1+1);
        }
       else if(str.length()>=2 and (str.substr(0,2))=="CD"){
            num =num +  400;
            str=str.substr(1+1);
        }
       else if(str.length()>=2 and (str.substr(0,2))=="CM"){
            num  = num + 900;
            str=str.substr(1+1);
        }
        else if(str.substr(0,1)=="I"){
            num  = num + 1;
            str=str.substr(1);
        }
       else if(str.substr(0,1)=="V"){
            num  = num + 5;
            str=str.substr(1);
        }
        else if(str.substr(0,1)=="X"){
            num  = num + 10;
            str=str.substr(1);
        }
                else if(str.substr(0,1)=="L"){
            num  = num + 50;
            str=str.substr(1);
        }
                else if(str.substr(0,1)=="C"){
            num  = num + 100;
            str=str.substr(1);
        }
                else if(str.substr(0,1)=="D"){
            num = num + 500;
            str=str.substr(1);
        }
                else if(str.substr(0,1)=="M"){
            num  = num + 1000;
            str=str.substr(1);
        }
        
    }
    
    return num;    
        
    }