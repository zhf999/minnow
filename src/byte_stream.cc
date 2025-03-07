#include "byte_stream.hh"
#include <cassert>

using namespace std;

ByteStream::ByteStream( uint64_t capacity )
  : capacity_( capacity ),buffer_()
{

}

void Writer::push( string data )
{
  uint64_t remain = available_capacity();
  if(data.size()>remain)
  {
    data.resize(remain);
  }

  buffer_.append(data);
  bytes_pushed_ += data.size();
}

void Writer::close()
{
  is_closed_ = true;
}

bool Writer::is_closed() const
{
  return is_closed_;
}

uint64_t Writer::available_capacity() const
{
  return capacity_-buffer_.size();
}

uint64_t Writer::bytes_pushed() const
{
  return bytes_pushed_; // Your code here.
}

string_view Reader::peek() const
{
  return {buffer_};
}

void Reader::pop( uint64_t len )
{
  if(len>buffer_.size())
    len = buffer_.size();
  buffer_.erase(0,len);
  bytes_popped_ += len;
}

bool Reader::is_finished() const
{
  return is_closed_&&buffer_.empty(); // Your code here.
}

uint64_t Reader::bytes_buffered() const
{
  return buffer_.size(); // Your code here.
}

uint64_t Reader::bytes_popped() const
{
  return bytes_popped_; // Your code here.
}

