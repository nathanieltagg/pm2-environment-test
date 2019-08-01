# Proof of principle failure for pm2 cluster mode

Works only on linux, although a Mac OSX version fails the same way with DYLD_LIBRARY_PATH.

Clone this repository.
To install this proof-of-principle, cd to the repo directory, and:
```bash
 $ npm install
 $ node-gyp rebuild
 $ cd ExternalLibraries
 $ make
 $ cd ..
 ```

 To illustrate the issue:
 ```bash
  $ export LD_LIBRARY_PATH=$PWD/ExternalLibrary
  $ node index.js
 ```
This works, giving the results of the C++ library calls.
```
start process. In this process the library path is set to: /home/tagg/environment-test/ExternalLibrary
Calling builtin function. Result:99
Calling library function. Result:98
done
^C
```

But if you unset the library:
```bash
  $ export LD_LIBRARY_PATH=
  $ node.js
 ```
 it fails with a dlopen error.

 To see the effect with PM2, run the included ecosystem file, which correctly sets the path.
 ```bash
   $ pm2 start environment.json
 ```
 As you can see from the logs, the fork invocation succeeds, and the cluster invocation does *not*.

 Requiring the builtin node cluster module and forking clusters runs them fine.. so long as the master process is in invocation mode.

