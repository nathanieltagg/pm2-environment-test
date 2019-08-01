{
  "targets": [
    {
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ],
      "target_name": "addon",
      "sources": [ "wrapper.cc" ],
	   "libraries": [
	        "-L ../ExternalLibrary -l extlib"
	      ],
	    "link_settings": {
	    	"libraries": []
	    }
    }
  ]
}
