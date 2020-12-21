void generatePath(){    
    int length;
    
    for(length=0; data[length] != '\0'; length++){
        //nothing
    }

    int i;
    for(i=0; i<length; i++){
        if(data[i] == 'B'){
            replace_path(i);
            refresh_path(length);
            i=0;
        }
    }
    
    inverse_path();

}

void replace_path(int i){
    if(data[i-1] == 'L' && data[i+1] == 'R'){
        data[i-1]='0';
        data[i]='B';
        data[i+1]='0';
    }

    else if(data[i-1] == 'L' && data[i+1] == 'S'){
        data[i-1]='0';
        data[i]='R';
        data[i+1]='0';
    }

    else if(data[i-1] == 'R' && data[i+1] == 'L'){
        data[i-1]='0';
        data[i]='B';
        data[i+1]='0';
    }

    else if(data[i-1] == 'S' && data[i+1] == 'L'){
        data[i-1]='0';
        data[i]='R';
        data[i+1]='0';
    }

    else if(data[i-1] == 'S' && data[i+1] == 'S'){
        data[i-1]='0';
        data[i]='B';
        data[i+1]='0';
    }

    else if(data[i-1] == 'L' && data[i+1] == 'L'){
        data[i-1]='0';
        data[i]='S';
        data[i+1]='0';
    }
}

void refresh_path(int length){

    int j=0,k=0;
    char refresh_temp[length+2];

    for(k=0; k<length; k++){
        if(data[k] != '0'){
            refresh_temp[j] = data[k];
            j++;
        }
    }

    for(k=j; k<length; k++){
        refresh_temp[k] = '\0';
    }

    for(k=0; k<length; k++){
        data[k] = refresh_temp[k];
    }
}

void inverse_path(){

   int finalLength, j, k;

   for(finalLength=0; data[finalLength] != '\0'; finalLength++){
        //nothing
   }

   char inverse_temp[finalLength+2];

   for(j=0,k=finalLength-1; k>=0; j++, k--){
       inverse_temp[j] = data[k];
   }

   for(j=0; j<finalLength; j++){
       data[j] = inverse_temp[j];
   }
   
   for(j=0; j<finalLength; j++){

       if(inverse_temp[j] == 'L'){
           data[j] = 'R';
       }
       else if(inverse_temp[j] == 'R'){
           data[j] = 'L';
       }
       else {
           data[j] = inverse_temp[j];
       }
   }
}


