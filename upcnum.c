
int adding(long upc, int counter, int odds_group, int evens_group) {
  int current_digit = upc % 10;
  if (counter == 0) {
    return 10 - (((odds_group * 3) + evens_group) % 10);
  }
  
  if (counter % 2 == 0) {
    return adding((upc - current_digit) / 10, counter - 1, odds_group, 
    evens_group + current_digit);
  } else {
    return adding((upc - current_digit) / 10, counter - 1, 
    odds_group + current_digit, evens_group);
  }
}
// validate_upc(upc) returns true if the last digit of upc is the correct
//   check digit and false otherwise.
// requires: upc is a 12 digit positive number

bool validate_upc(long upc) {
  // your implementation goes here
  int key = upc % 10;
  long new_num = (upc - key) / 10;
  int summation = adding(new_num, 11, 0, 0);
  
  if (summation == key){
    return true;
  } else {
    return false;
  }
  
  
}
