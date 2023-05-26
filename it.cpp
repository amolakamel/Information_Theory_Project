
using namespace std;

/*
void ShrOOk() {

 ios_base::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr); 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r" , stdin), 
    freopen("output.txt","w",stdout);
    #endif
}
  
 */

// From Binary to Decimal
int to_decimal(vector < int > &v){
  reverse(all(v));
 
  int ans = 0 , x = 1;
  for(int i = 0 ; i < sz(v) ; i++){
    if(v[i])
      ans += x;

    x *= 2;
  }
  return ans ;
}

void Encoded(){

    // -----------------------------> Encoding <-----------------------------//

  
    int CodeWord_sz , DataWord_sz , Parity_sz_C;
    cin >> CodeWord_sz >> DataWord_sz;
    
    // number of Columns of parity matrix
    Parity_sz_C = CodeWord_sz - DataWord_sz ;
    
    // number of rows of parity matrix =  DataWord_sz

    vector < int > message(DataWord_sz) , Encoded_message;

    //Enter message code 
    cin(message);
   
    vector < vector < int > > Parity_Matrix ( DataWord_sz , vector < int > (Parity_sz_C)) , identity ( DataWord_sz , vector < int > (DataWord_sz)) , Generator ;


     // Enter Parity_Matrix
    cin_2d(Parity_Matrix , DataWord_sz , Parity_sz_C);
    
    
    // Costruct identity matrix 
    for(int i = 0 ; i < DataWord_sz ; i++)
      for(int j = 0 ; j < DataWord_sz ; j++)

         if(i == j) identity[i][j] = 1;
         else identity[i][j] = 0;


  // Costruct Generator matrix 
   Generator = identity;

    for(int i = 0 ; i < DataWord_sz ; i++)
      for(int j = 0 ; j < Parity_sz_C ; j++){
        Generator[i].push_back(Parity_Matrix[i][j]);
    }

    // Encoded Step
    int Xor = 0;
    for(int i = 0 ; i < CodeWord_sz ; i++){
      Xor = 0;
      for(int j = 0 ; j < DataWord_sz ; j++){

       Xor = (Xor ^ (message[j % 3] * Generator[j][i]));

    }
      Encoded_message.push_back(Xor);
  } 
   // Finally , Encoded message is ready for you  ^_^
   cout << "The Encoded_message is : ";
    cout (Encoded_message);
    cout << nl;


}
void Decoded(){
            
   //_____________________________________________________________________//

   // --------------------------> Decoding <-----------------------------//

    
    int CodeWord_sz , DataWord_sz , Parity_sz_C;
    cin >> CodeWord_sz >> DataWord_sz;
    
    // number of Columns of parity matrix
    Parity_sz_C = CodeWord_sz - DataWord_sz ;
    
    // number of rows of parity matrix =  DataWord_sz


   vector < vector < int > > Parity_transpose ( Parity_sz_C , vector < int > (DataWord_sz)) , Parity_Matrix ( DataWord_sz , vector < int > (Parity_sz_C)) , identity ( DataWord_sz , vector < int > (DataWord_sz)), Generator_2 ;
    
    // Enter Parity_Matrix
    cin_2d(Parity_Matrix , DataWord_sz , Parity_sz_C);


    // Costruct identity matrix 
    for(int i = 0 ; i < DataWord_sz ; i++)
      for(int j = 0 ; j < DataWord_sz ; j++)

         if(i == j) identity[i][j] = 1;
         else identity[i][j] = 0;


   vector < int > decoded_message , checked_code(CodeWord_sz);


      cin(checked_code);


     for(int i = 0 ; i < Parity_sz_C ; i++)
      for(int j = 0 ; j < DataWord_sz ; j++){
        Parity_transpose[i][j] = (Parity_Matrix[j][i]);
    }
    
    // Costruct  Generator_2  matrix
    
     Generator_2 =  Parity_transpose;

     for(int i = 0 ; i < DataWord_sz ; i++)
      for(int j = 0 ; j < DataWord_sz ; j++){
        Generator_2[i].push_back(identity[i][j]);
    }

    // cout2d(Generator_2);
    // cout << nl;

    int Xor2 = 0;
    for(int i = 0 ; i < DataWord_sz ; i++){
      Xor2 = 0;
      for(int j = 0 ; j < CodeWord_sz ; j++){

       Xor2 = (Xor2 ^ (checked_code[j] * Generator_2[i][j]));

    }
      decoded_message.push_back(Xor2);
  } 

  cout << " The Decoded_message is : ";
  cout(decoded_message);
  cout << nl ;

  int check = to_decimal(decoded_message);
  if(check)
    cout << " There's an error in the " << check  << "th bit" << nl << nl;
  
  else
 cout << " The Code_Word is correct " << nl << nl;

}
//_______________________________________My_code___________________________________________//

void solve()
{
  
   cout << " HeLLo There , Welcome to our App in which you can Encode and Decode messages as you want \n";
   cout << " We hope you have a great time in our App  ✿ ◠‿◠ ✿\n\n";

   cout << " please if you want to Encode a message press 1 otherwise press 2 ..\n\n";
   
   int n ; cin >> n;


   if(n == 1){
     cout << " To Encode your message , Please Enter all of these in the Order ...✿✿ \n \n ( 1 : The Code Word Size  )\n ( 2 : The Data Word Size )\n ( 3 : Parity Matrix )\n ( 4 : Your message that you want to Encode )\n\n\n ";
  

        Encoded();

     cout << "\n Thanks for your participation  ✿ ◠‿◠ ✿ ";
   }
   else{

     cout << " To Decode your message , Please Enter all of these in the Order ...✿✿ \n \n ( 1 : The Code Word Size  )\n ( 2 : The Data Word Size )\n ( 3 : Parity Matrix )\n ( 4 : Your message that you want to Decode )\n\n\n";
  

         Decoded();

     cout << "\n Thanks for your participation  ✿ ◠‿◠ ✿ ";
      
   }
      
      
}


//********************************************************************************************

int main()
{

   //ShrOOk();
 
   int t=1;
  //  cin>>t;
   while(t--)
   {
    
       solve();
       cout<<nl;
   }


    return 0;
}

/* 
 
*/