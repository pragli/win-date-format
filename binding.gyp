{
  "targets": [
    {
      "target_name": "culture",
      "conditions": [
        ['OS == "win"', {
          'msbuild_settings': {
            'ClCompile': {
              'CompileAsManaged':'true',
              "ExceptionHandling": "Async", 
            }
          },
          "sources": [
            "Culture.cc"
          ]
        }]
      ]
    }
  ]
}
