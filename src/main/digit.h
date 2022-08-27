struct clockface {
  int16_t angleBack;    //smallest angle (0, 90, 180, 225, 270 )
  int16_t angleFront;     //largest  angle (0, 90, 180, 225, 270 )
  bool    clear;         //clear if at 225
  bool    extra;         //draw extra needle at 180
};

const clockface digit[34][6] = 
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
    {180, 225, false, false},
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
    { 270, 270, false, true},
    {   0,  90, false, false},
    {   0, 270, false, false},
  },
// digit 7
  {
    {  90,  90, false, false},
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
    {   0,  90, false, false},
    {   0, 270, false, true},
    {  90,  90, false, false},
    {   0, 270, false, false},
  },
// digit rand A 0
  {   
    { 45, 315, false, false},
    { 45, 90, false, false},
    { 45, 270, false, false},
    { 90, 90, false, false},
    { 135, 180, false, false},
    { 180, 225, false, false},
  },
// digit rand A 45
  {   
    { 90, 0, false, false},
    { 90, 135, false, false},
    { 90, 315, false, false},
    { 135, 135, false, false},
    { 180, 225, false, false},
    { 225, 270, false, false},
  },
// digit rand A 90
  {   
    { 135, 45, false, false},
    { 135, 180, false, false},
    { 135, 0, false, false},
    { 180, 180, false, false},
    { 225, 270, false, false},
    { 270, 315, false, false},
  },
// digit rand A 135
  {   
    { 180, 90, false, false},
    { 180, 225, false, false},
    { 180, 45, false, false},
    { 225, 225, false, false},
    { 270, 315, false, false},
    { 315, 0, false, false},
  },
// digit rand A 180
  {   
    { 225, 135, false, false},
    { 225, 270, false, false},
    { 225, 90, false, false},
    { 270, 270, false, false},
    { 315, 0, false, false},
    { 0, 45, false, false},
  },
// digit rand A 225
  {   
    { 270, 180, false, false},
    { 270, 315, false, false},
    { 270, 135, false, false},
    { 315, 315, false, false},
    { 0, 45, false, false},
    { 45, 90, false, false},
  },
// digit rand A 270
  {   
    { 315, 225, false, false},
    { 315, 0, false, false},
    { 315, 180, false, false},
    { 0, 0, false, false},
    { 45, 90, false, false},
    { 90, 135, false, false},
  },
// digit rand A 315
  {   
    { 0, 270, false, false},
    { 0, 45, false, false},
    { 0, 225, false, false},
    { 45, 45, false, false},
    { 90, 135, false, false},
    { 135, 180, false, false},
  },
// digit rand B 0
  {   
    { 0, 315, false, false},
    { 225, 90, false, false},
    { 45, 270, false, false},
    { 225, 225, false, false},
    { 135, 270, false, false},
    { 270, 225, false, false},
  },
// digit rand B 45
  {   
    { 45, 0, false, false},
    { 270, 135, false, false},
    { 90, 315, false, false},
    { 270, 270, false, false},
    { 180, 315, false, false},
    { 315, 270, false, false},
  },
// digit rand B 90
  {   
    { 90, 45, false, false},
    { 315, 180, false, false},
    { 135, 0, false, false},
    { 315, 315, false, false},
    { 225, 0, false, false},
    { 0, 315, false, false},
  },
// digit rand B 135
  {   
    { 135, 90, false, false},
    { 0, 225, false, false},
    { 180, 45, false, false},
    { 0, 0, false, false},
    { 270, 45, false, false},
    { 45, 0, false, false},
  },
// digit rand B 180
  {   
    { 180, 135, false, false},
    { 45, 270, false, false},
    { 225, 90, false, false},
    { 45, 45, false, false},
    { 315, 90, false, false},
    { 90, 45, false, false},
  },
// digit rand B 225
  {   
    { 225, 180, false, false},
    { 90, 315, false, false},
    { 270, 135, false, false},
    { 90, 90, false, false},
    { 0, 135, false, false},
    { 135, 90, false, false},
  },
// digit rand B 270
  {   
    { 270, 225, false, false},
    { 135, 0, false, false},
    { 315, 180, false, false},
    { 135, 135, false, false},
    { 45, 180, false, false},
    { 180, 135, false, false},
  },
// digit rand B 315
  {   
    { 315, 270, false, false},
    { 180, 45, false, false},
    { 0, 225, false, false},
    { 180, 180, false, false},
    { 90, 225, false, false},
    { 225, 180, false, false},
  },
// digit rand C 0
  {   
    { 0, 315, false, false},
    { 135, 45, false, false},
    { 45, 270, false, false},
    { 180, 45, false, false},
    { 135, 180, false, false},
    { 270, 45, false, false},
  },
// digit rand C 45
  {   
    { 45, 0, false, false},
    { 180, 90, false, false},
    { 90, 315, false, false},
    { 225, 90, false, false},
    { 180, 225, false, false},
    { 315, 90, false, false},
  },
// digit rand C 90
  {   
    { 90, 45, false, false},
    { 225, 135, false, false},
    { 135, 0, false, false},
    { 270, 135, false, false},
    { 225, 270, false, false},
    { 0, 135, false, false},
  },
// digit rand C 135
  {   
    { 135, 90, false, false},
    { 270, 180, false, false},
    { 180, 45, false, false},
    { 315, 180, false, false},
    { 270, 315, false, false},
    { 45, 180, false, false},
  },
// digit rand C 180
  {   
    { 180, 135, false, false},
    { 315, 225, false, false},
    { 225, 90, false, false},
    { 0, 225, false, false},
    { 315, 0, false, false},
    { 90, 225, false, false},
  },
// digit rand C 225
  {   
    { 225, 180, false, false},
    { 0, 270, false, false},
    { 270, 135, false, false},
    { 45, 270, false, false},
    { 0, 45, false, false},
    { 135, 270, false, false},
  },
// digit rand C 270
  {   
    { 270, 225, false, false},
    { 45, 315, false, false},
    { 315, 180, false, false},
    { 90, 315, false, false},
    { 45, 90, false, false},
    { 180, 315, false, false},
  },
// digit rand C 315
  {   
    { 315, 270, false, false},
    { 90, 0, false, false},
    { 0, 225, false, false},
    { 135, 0, false, false},
    { 90, 135, false, false},
    { 225, 0, false, false},
  }
};
