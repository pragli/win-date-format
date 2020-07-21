#include <node.h>
#include <nan.h>
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

NAN_METHOD(getDateFormat) {
  Isolate* isolate = info.GetIsolate();

  const char * shortCultureFormat = getDateFormatM();
  info.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, shortCultureFormat));

  freeStr(shortCultureFormat);
}

NAN_MODULE_INIT(InitAll) {
  Nan::Set(target, Nan::New("getDateFormat").ToLocalChecked(),
    Nan::GetFunction(Nan::New<v8::FunctionTemplate>(getDateFormat)).ToLocalChecked());
}

NODE_MODULE(culture, InitAll)
