#include "protocol.h"

Frame::Frame(){
  head = FRAME_HEAD;
  tail = FRAME_TAIL;
}
Frame::Frame(const uchar mType,const uchar* mId){
  head = FRAME_HEAD;
  tail = FRAME_TAIL;
  type = mType;
  for(int i = 0;i<5;i++){
    id[i] = mId[i];
  }
}
void Frame::set(const uchar mType,const uchar* mId){
  type = mType;
  for(int i = 0;i<5;i++){
    id[i] = mId[i];
  }
}
void Frame::setType(const uchar mType){
  type = mType;
}
void Frame::setID(const uchar *mId){
  for(int i = 0;i<5;i++){
    id[i] = mId[i];
  }
}
uchar Frame::getType(){
  return type;
}
uchar * Frame::getId(){
  return id;
}


