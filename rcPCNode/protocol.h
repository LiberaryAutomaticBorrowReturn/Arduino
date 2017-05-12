#ifndef PROTOCOL
#define FRAME_HEAD (0x0F)
#define FRAME_TAIL (0xF0)
#define READCARD (0x00)
#define BOOKTAG (0x01)


#define uchar unsigned char
class Frame{
  private:
  uchar head;
  uchar type;
  uchar id[5];
  uchar tail;
  public:
  Frame();
  Frame(const uchar mType,const uchar* mId);
  void set(const uchar mType,const uchar* mId); 
  void setBuff(uchar *buff);
  void setType(const uchar mType);
  void setID(const uchar *mId);
  uchar getType();
  uchar * getId();
  void getBuff(uchar *buff);
};
#endif
