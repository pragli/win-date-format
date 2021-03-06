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
  info.GetReturnValue().Set(Nan::New<v8::String>(shortCultureFormat).ToLocalChecked());

  freeStr(shortCultureFormat);
}

NAN_MODULE_INIT(InitAll) {
  NAN_EXPORT(target, getDateFormat);
}

NODE_MODULE(culture, InitAll)
