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
void Frame::setBuff(uchar *buff){
  head = buff[0];
  type = buff[1];
  for(int i = 0;i<5;i++){
    id[i] = buff[2+i];
  }
  tail = buff[7];
}
void Frame::getBuff(uchar *buff){
  buff[0] = head;
  buff[1] = type;
  for(int i = 0 ;i <5;i++){
    buff[2+i] = id[i];
  }
  buff[7] = tail;
}

