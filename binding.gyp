{
  "targets": [
    {
      "target_name": "culture",
      "conditions": [
        ['OS == "win"', {
          "include_dirs" : [
            "<!(node -e \"require('nan')\")"
          ],
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
