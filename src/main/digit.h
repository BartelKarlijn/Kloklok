struct clockface {
  int16_t angleBack;    //smallest angle (0, 90, 180, 225, 270 )
  int16_t angleFront;     //largest  angle (0, 90, 180, 225, 270 )
  bool    clear;         //clear if at 225
  bool    extra;         //draw extra needle at 180
};

clockface digit[10][6] = 
{ 
// digit 0
  {   
    { 90, 180, false, false},
    {180, 270, false, false},
    {  0, 180, false, false},
    {  0, 180, false, false},
    {  0,  90, false, false},
    {  0, 270, false, false},
  },
// digit 1
  {   
    {225, 225, true, false},
    {180, 180, false, false},
    {225, 225, true, false},
    {  0, 180, false, false},
    {225, 225, true, false},
    {  0,   0, false, false},
  },
// digit 2
  {   
    { 90,  90, false, false},
    {180, 270, false, false},
    { 90, 180, false, false},
    {  0, 270, false, false},
    {  0,  90, false, false},
    {270, 270, false, false},
  },
// digit 3
  {   
    { 90,  90, false, false},
    {180, 270, false, false},
    { 90,  90, false, false},
    {  0, 270, false, false},
    { 90,  90, false, false},
    {  0, 270, false, false},
  },
// digit 4
  {   
    { 180, 180, false, false},
    { 180, 180, false, false},
    {   0,  90, false, false},
    {   0, 270, false, true},
    { 225, 225, true, false},
    {   0,   0, false, false},
  },
// digit 5
  {   
    {  90, 180, false, false},
    { 270, 270, false, false},
    {   0,  90, false, false},
    { 180, 270, false, false},
    {  90,  90, false, false},
    {   0, 270, false, false},
  },
// digit 6
  {
    {  90, 180, false, false},
    { 270, 270, false, false},
    {   0,  90, false, true},
    {   0, 270, false, true},
    {   0,  90, false, false},
    {   0, 270, false, false},
  },
// digit 7
  {
    {  90, 180, false, false},
    { 180, 270, false, false},
    { 225, 225, true, false},
    {   0, 180, false, false},
    { 225, 225, true, false},
    {   0,   0, false, false},
  },
// digit 8
  {
    {  90, 180, false, false},
    { 180, 270, false, false},
    {   0,  90, false, true},
    {   0, 270, false, true},
    {   0,  90, false, false},
    {   0, 270, false, false},
  },
// digit 9
  {   
    {  90, 180, false, false},
    { 180, 270, false, false},
    {   0, 180, false, false},
    {   0, 270, false, true},
    {  90,  90, false, false},
    {   0, 270, false, false},
  }
};
