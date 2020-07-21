#include <node.h>
#include <v8.h>

#pragma managed

using namespace System;
using namespace System::Globalization;
using namespace System::Runtime::InteropServices;

const char * getDateFormatM() {
   System::String ^ shortDatePattern = CultureInfo::CurrentCulture->DateTimeFormat->ShortDatePattern;
   const char* str = (const char*)(void*) Marshal::StringToHGlobalAnsi(shortDatePattern);
   return str;
}

void freeStr(const char* str) {
   Marshal::FreeHGlobal(System::IntPtr((void*) str));
}

#pragma unmanaged

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void getDateFormat(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  const char * shortCultureFormat = getDateFormatM();
  args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, shortCultureFormat));

  freeStr(shortCultureFormat);
}

void init(Local<v8::Object> exports) {
  NODE_SET_METHOD(exports, "getDateFormat", getDateFormat);
}

NODE_MODULE(culture, init)
